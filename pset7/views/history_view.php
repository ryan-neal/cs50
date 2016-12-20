<table class = "table-striped">
    <tr>
    <th>Symbol</th>
    <th>Status</th>
    <th>Shares</th> 
    <th>Price</th>
    <th>Total</th>
    </tr>

    <?php foreach ($history as $hist): ?>
        <tr>
            <td><?= $hist["symbol"] ?></td>
            <td><?= $hist["status"] ?></td>
            <td><?= $hist["shares"] ?></td>
            <td><?= $hist["price"] ?></td>
            <td><?= $hist["date"]?></td>
        </tr>
<?php endforeach ?>