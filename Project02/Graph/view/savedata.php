<?php
$node1 = $_POST['node1'];
$node2 = $_POST['node2'];

echo "$node1 $node2";

$fp = fopen("homework3_responses.csv", "a"); 

$save = fwrite($fp, "\n". $node1 . "," . $node2);
 
fclose($fp); 

?>