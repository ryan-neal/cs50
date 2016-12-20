<?php
    
    $price = number_format($stock['price'], 2, '.', ',');
    print("A share of {$stock['symbol']} costs $price");

?>