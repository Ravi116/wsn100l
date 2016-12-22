// coursework p00602 2012
// Peter Haban
// database upload php script, used by master node/concentrator
// version 1.0 - coursework demonstration

<?php
// declare DATA variables
$DATA1 = $_REQUEST['temp'];
$DATA2 = $_REQUEST['humid'];
$DATA3 = $_REQUEST['light'];
$DATA4 = $_REQUEST['s_temp'];
$DATA5 = $_REQUEST['s_humid'];
$DATA6 = $_REQUEST['tank'];
$DATA7 = $_REQUEST['id'];

// connect to the database host
$con = mysql_connect("localhost","root","blue");
if (!$con)
  {
  die('Could not connect: ' . mysql_error());
  }
  
// select database
mysql_select_db("arduino", $con);

// insert the DATA variables into the corresponding columns in the p00602 table
mysql_query("INSERT INTO p00602 (date, temp, humid, light, s_temp, s_humid, tank, id)
VALUES (NOW(), $DATA1, $DATA2, $DATA3, $DATA4, $DATA5, $DATA6, $DATA7)");


// close connection
mysql_close($con);
?>
