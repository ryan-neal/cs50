<?php

    // configuration
    require("../includes/config.php");
    
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // check if passwords are empty
        if(empty($_POST["password"]) or (empty($_POST["confirmation"])))
        {
            apologize("Please enter a password!");
        }
        
        if($_POST["password"] != $_POST["confirmation"])
        {
            apologize("Passwords don't match!");    
        }
        
        if(empty($_POST["username"]))
        {
            apologize("Please enter a username!");
        }
        
        $result = CS50::query("INSERT IGNORE INTO users (username, hash, cash) VALUES(?, ?, 10000.0000)", $_POST["username"], password_hash($_POST["password"], PASSWORD_DEFAULT));
        if($result == false)
        {
            apologize("That username already exists");
        }
        else
        {
            CS50::query("INSERT IGNORE INTO users (username, hash, cash) VALUES(?, ?, 10000.0000)", $_POST["username"], password_hash($_POST["password"], PASSWORD_DEFAULT));
            $rows = CS50::query("SELECT LAST_INSERT_ID() AS id");
            $id = $rows[0]["id"];
            $_SESSION["id"];
        }
    }

?>