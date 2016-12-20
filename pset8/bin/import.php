#!/usr/bin/env php
<?php
    require("../includes/config.php");
    $myFile = $argv[1];
    
    if(file_exists($myFile) == false)
    {
        echo ("File doesn't exist");
        exit();
    }
    
    if(is_readable($myFile))
    {
        $file = fopen($myFile, "r" );
        if($file == false ) 
        {
            echo ("Error in opening file");
            exit();
        }
    
        while (($data = fgetcsv($file, 1000, "\t")) !== FALSE)
        {
            $result = cs50::query("INSERT INTO places 
            ('country_code', 'postal_code', 'admin_name1', 'admin_code1', 'admin_name2', 'admin_code2', 'admin_name3', 'admin_code3', 'latitude', 'longitude'),
            VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", 
            $data[0], 
            $data[1], 
            $data[2], 
            $data[3], 
            $data[4], 
            $data[5], 
            $data[6], 
            $data[7], 
            $data[8], 
            $data[9], 
            $data[10], 
            $data[11]);
        
        }
    }


?>