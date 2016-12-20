<?php

    // configuration
    require("../includes/config.php"); 
    
    $rows = cs50::query("select symbol, shares from portfolio where user_id = ?", $_SESSION["id"]);
    $cash1 = cs50::query("select cash from users where id = ?", $_SESSION["id"]);
    $cash = number_format($cash1[0]['cash'], 2, '.', ',');
    
    $positions = [];
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
        {
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $row["shares"],
                "symbol" => $row["symbol"]
                ];
        }
    }

    // render portfolio
    render("portfolio.php", ["positions" => $positions, "cash" => $cash, "title" => "Portfolio"]);

?>
