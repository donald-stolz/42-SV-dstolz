<?php
session_start();
require_once("dbcontroller.php");
require_once("install.php");
$db_handle = new DBController();
if (!empty($_GET["action"]))
{
    switch($_GET["action"])
    {
        case "add":
            if(!empty($_POST["quantity"]))
            {
		        $productByid = $db_handle->runQuery("SELECT * FROM spacetbl WHERE id='" . $_GET["id"] . "'");
                $itemArray = array($productByid[0]["id"]=>array('name'=>$productByid[0]["name"], 'id'=>$productByid[0]["id"], 'quantity'=>$_POST["quantity"], 'price'=>$productByid[0]["price"], 'image'=>$productByid[0]["image"]));		
            if(!empty($_SESSION["cart_item"]))
            {
                if(in_array($productByid[0]["id"],array_keys($_SESSION["cart_item"])))
                {
                    foreach($_SESSION["cart_item"] as $key => $v)
                    {
                            if($productByid[0]["id"] == $key)
                            {
                                if(empty($_SESSION["cart_item"][$key]["quantity"]))
                                {
								    $_SESSION["cart_item"][$key]["quantity"] = 0;
							    }
							    $_SESSION["cart_item"][$key]["quantity"] += $_POST["quantity"];
						    }
				    }
                }
                else
                {
				    $_SESSION["cart_item"] = array_merge($_SESSION["cart_item"],$itemArray);
			    }
            }
            else
            {
			    $_SESSION["cart_item"] = $itemArray;
		    }
	        }
        break;
        case "remove":
            if(!empty($_SESSION["cart_item"]))
            {
               foreach($_SESSION["cart_item"] as $key => $value)
               {
		    	    if($_GET["id"] == $key)
		    		    unset($_SESSION["cart_item"][$key]);				
		    	    if(empty($_SESSION["cart_item"]))
		    		    unset($_SESSION["cart_item"]);
		        }
	      }
	       break;
       case "empty":
    	    unset($_SESSION["cart_item"]);
            break;
    }
}
?>
<HTML>
    <HEAD>
        <TITLE>Space Supplies</TITLE>
        <link href="style.css" type="text/css" rel="stylesheet" />
</HEAD>
<BODY>
      <div id="shopping cart">
          <div class="txt-heading">Shopping Cart</div>
          <a id="btnEmpty" href="index.php?action=empty">Empty Cart</a>
<?php
if (isset($_SESSION["cart_item"]))
{
    $total_qn = 0;
    $total_pr = 0;
    ?>
<table class="tbl-cart" cellpadding="10" cellspacing="1">
    <tbody>
        <tr>
            <th style="text-align: left;">Name</th>
            <th style="text-align: left;">id</th>
            <th style="text-align: right;" width="5%">Quantity</th>
            <th style="text-align: right;" width="10%">Unit Price</th>
            <th style="text-align: right;" width="10%">Price</th>
            <th style="text-align: center;" width="5%">Remove</th>
        </tr>
        <?php
    $total_qn += $item["quantity"];
    $total_pr += ($item["price"] * $item["quantity"]);

?>
<tr>
    <td colspan="2" align="right">Total:</td>
    <td align="right"><?php echo $total_qn; ?></td>
    <td colspan="2" align="right"><strong><?php echo "$ ".number_format($total_pr, 2); ?></strong></td>
    <td></td>
</tr>
</tbody>
</table>
<?php 
}
else {
    ?>
<div class="no-records">Your Cart is Empty</div>
<?php
}
?>
</div>
<div id="product-grid">
    <div class="txt-heading">Products</div>
    <?php
$product_array = $db_handle->runQuery("SELECT * FROM spacetbl ORDER BY id ASC");
$product_array = $db_handle->runQuery("SELECT * FROM spacetbl ORDER BY id ASC");
if (!empty($product_array)) { 
	foreach($product_array as $key=>$value){
?>
	<div class="product-item">
		<form method="post" action="index.php?action=add&id=<?php echo $product_array[$key]["id"]; ?>">
		<div class="product-image"><img src="<?php echo $product_array[$key]["image"]; ?>"></div>
		<div class="product-tile-footer">
		<div class="product-title"><?php echo $product_array[$key]["name"]; ?></div>
		<div class="product-price"><?php echo "$".$product_array[$key]["price"]; ?></div>
		<div class="cart-action"><input type="text" class="product-quantity" name="quantity" value="1" size="2" /><input type="submit" value="Add to Cart" class="btnAddAction" /></div>
    </div>
		</form>
	</div>
<?php
	}
}
?>
</BODY>
</HTML>
