<table class = "table-striped">
    <tr>
    <th>Symbol</th>
    <th>Name</th>
    <th>Shares</th> 
    <th>Price</th>
    <th>Total</th>
    </tr>

    <?php foreach ($positions as $position): ?>
        <tr>
            <td><?= $position["symbol"] ?></td>
            <td><?= $position["name"] ?></td>
            <td><?= $position["shares"] ?></td>
            <td><?= number_format($position["price"], 2, '.', ',') ?></td>
            <td><?= number_format(($position["shares"] * $position["price"]), 2, '.', ',') ?></td>
        </tr>
<?php endforeach ?>
    <tr>
        <td> <b>Cash </b> </td>
        <td> </td>
        <td> </td>
        <td> </td>
        <td><?php print($cash) ?></td>
    </tr>
      </table> 
