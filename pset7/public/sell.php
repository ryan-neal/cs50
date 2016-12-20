<?php

    require("../includes/config.php");
    
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        $symbol = cs50::query("select symbol from portfolio where user_id = ?", $_SESSION["id"]);
        
        // else render form
        render("sell_form.php", ["symbol" => $symbol]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $rows = cs50::query("select * from portfolio where user_id = ? and symbol = ?", $_SESSION["id"], $_POST["symbol"]);
        
        $positions = [];
        foreach ($rows as $row)
        {   
            $stock = lookup($row["symbol"]);
            if ($stock !== false)
            {
                $positions[] = [
                    "price" => $stock["price"],
                    "shares" => $row["shares"],
                    "symbol" => $row["symbol"]
                    ];
            }
        }
        
        $new_cash = $positions[0]['price'] * $positions[0]['shares'];
        print($new_cash);
        
        cs50::query("DELETE from portfolio where user_id = ? and symbol = ?", $_SESSION["id"], $_POST["symbol"]);
        cs50::query("UPDATE users SET cash = cash + ? where id = ?", $new_cash, $_SESSION["id"]);
        cs50::query("INSERT into history (status, symbol, shares, price, id, date) VAlUES(?, ?, ?, ?, ?, Now())", "Sell", $row["symbol"], $row["shares"], $stock["price"], $_SESSION["id"]);
        
        redirect("index.php");
    }

?>