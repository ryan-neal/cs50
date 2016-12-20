
<form action="sell.php" method="POST">
    <fieldset>
        <div class="form-group">
        </div>
        <div>
        <?php
            echo "<select name='symbol'>";
            foreach($symbol as $row)
            {
                echo "<option value='".$row["symbol"]."'>".$row["symbol"]."</option>";            
            }
            echo "</select>";
        ?>
        </div>
        <div class="form-group">
            <button type="submit" class="btn btn-default">Sell</button>
        </div>
    </fieldset>
</form>