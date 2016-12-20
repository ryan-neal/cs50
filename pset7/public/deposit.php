<?php

    require("../includes/config.php");
    
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        $cash = cs50::query("select cash from users where id = ?", $_SESSION["id"]);
        
        // else render form
        render("deposit_form.php", ["title" => "Deposit", "cash" => $cash]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if ($_POST["funds"] <= 0)
        {
            apologize("Please enter a positive amount of funds to deposit in your account, including cents.");
        }
        
        cs50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $_POST["funds"], $_SESSION["id"]);
        
        redirect("index.php");
    }

?>