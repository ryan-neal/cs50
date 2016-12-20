<?php

    // configuration
    require("../includes/config.php");
    
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("buy_form.php", ["title" => "Buy"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // check if shares or symbol is empty
        if(empty($_POST["shares"]) or (empty($_POST["symbol"])))
        {
            apologize("What would you like to buy?!");
        }
        
        if(preg_match("/^\d+$/", $_POST["shares"]) == (is_numeric($_POST["shares"] == false)))
        {
            apologize("Please enter integer values for shares");
        }
        
        $stock = lookup($_POST['symbol']);

        $cash1 = cs50::query("select cash from users where id = ?", $_SESSION["id"]);
        $cash = $cash1[0]['cash'];
        
        if(($stock['price']) * $_POST['shares'] > $cash)
        {
            apologize("Sorry, you don't have enough money :(");
        }
        
        $new_cash = $stock['price'] * $_POST['shares'];
        cs50::query("UPDATE users SET cash = cash - ? where id = ?", $new_cash, $_SESSION["id"]);
        cs50::query("INSERT INTO portfolio (user_id, symbol, shares) VALUES (?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + ?", $_SESSION["id"], strtoupper($stock['symbol']), $_POST["shares"], $_POST["shares"]);
        cs50::query("INSERT into history (status, symbol, shares, price, id, date) VAlUES(?, ?, ?, ?, ?, Now())", "Buy", strtoupper($stock["symbol"]), $_POST["shares"], $stock["price"], $_SESSION["id"]);
        
        redirect("index.php");
    }

?>