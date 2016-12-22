<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
 <head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <title>Graph of temperature readings from node 0</title>
    <link href="layout.css" rel="stylesheet" type="text/css"></link>
    <!--[if IE]><script language="javascript" type="text/javascript" src="flot/excanvas.min.js"></script><![endif]-->
    <script language="javascript" type="text/javascript" src="flot/jquery.js"></script>
    <script language="javascript" type="text/javascript" src="flot/jquery.flot.js"></script>
    <script language="javascript" type="text/javascript" src="flot/jquery.flot.selection.js"></script>
 </head>
    <body>
    <h1>Graph of temperature readings from node 0</h1>

    <p>Zoom to:
      <button id="nineties">half hour</button>
      <button id="ninetynine">1 hour</button>
      <button id="12hour">12 hours</button>
      <button id="24hour">24 hours</button>
      <button id="48hour">48 hours</button>
      <button id="Refresh">Refresh</button></p>
<?php

include 'DB.php';

$con = mysql_connect('localhost', 'root', 'blue');
$db = mysql_select_db('arduino', $con);

$result = mysql_query("SELECT date, (UNIX_TIMESTAMP(date)*1000) as stamp, temp FROM p00602 where id = 0 order by date");

$data = array();
$max = 0;
while($row = mysql_fetch_array($result))
{
  $data[] = array( $row['stamp'], $row['temp'] );
}

?>
    <div id="placeholder" style="width:800px;height:400px;"></div>

    <p></p>
    <div id="overview" style="margin-left:20px;margin-top:20px;width:780px;height:100px"></div>

<script id="source" language="javascript" type="text/javascript">

var data = <?php echo json_encode($data); ?>;

$(function () {

    var options = {
        xaxis: { mode: "time" },
        selection: { mode: "xy" },
    };
    
    var plot = $.plot($("#placeholder"), [ data ], options);
    
    var overview = $.plot($("#overview"), [ data ], {
        series: {
            lines: { show: true, lineWidth: 1 },
            shadowSize: 0
        },
        xaxis: { ticks: [], mode: "time" },
        yaxis: { ticks: [], min: 0, max: 5000 },
        selection: { mode: "xy" }
    });

  $("#placeholder").bind("plotselected", function (event, ranges) {
        // clamp the zooming to prevent eternal zoom
        if (ranges.xaxis.to - ranges.xaxis.from < 0.00001)
            ranges.xaxis.to = ranges.xaxis.from + 0.00001;
        if (ranges.yaxis.to - ranges.yaxis.from < 0.00001)
            ranges.yaxis.to = ranges.yaxis.from + 0.00001;
        
        // do the zooming
        plot = $.plot($("#placeholder"), [ data ],
                      $.extend(true, {}, options, {
                          xaxis: { min: ranges.xaxis.from, max: ranges.xaxis.to },
                          yaxis: { min: ranges.yaxis.from, max: ranges.yaxis.to }
                      }));
        
        // don't fire event on the overview to prevent eternal loop
        overview.setSelection(ranges, true);
    });

    
    $("#overview").bind("plotselected", function (event, ranges) {
        plot.setSelection(ranges);
    });

  $("#nineties").click(function () {
        $.plot($("#placeholder"), [data], {
            xaxis: {
                mode: "time",
                min: (new Date()).getTime()-1800000,
                max: (new Date()).getTime()
            },
            selection: { mode: "xy" }
        });
    });

    $("#ninetynine").click(function () {
        $.plot($("#placeholder"), [data], {
            xaxis: {
                mode: "time",
                min: (new Date()).getTime()-3600000,
                max: (new Date()).getTime()
            },
            selection: { mode: "xy" }
        });
    });

    $("#12hour").click(function () {
        $.plot($("#placeholder"), [data], {
            xaxis: {
                mode: "time",
                min: (new Date()).getTime()-43200000,
                max: (new Date()).getTime()
            },
            selection: { mode: "xy" }
        });
    });

    $("#24hour").click(function () {
        $.plot($("#placeholder"), [data], {
            xaxis: {
                mode: "time",
                min: (new Date()).getTime()-86400000,
                max: (new Date()).getTime()
            },
            selection: { mode: "xy" }
        });
    });

    $("#48hour").click(function () {
        $.plot($("#placeholder"), [data], {
            xaxis: {
                mode: "time",
                min: (new Date()).getTime()-172800000,
                max: (new Date()).getTime()
            },
            selection: { mode: "xy" }
        });
    });

    $("#Refresh").click(function () {

    });




});
</script>

 </body>
</html>
