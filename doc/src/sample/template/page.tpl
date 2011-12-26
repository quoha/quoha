<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="en" xml:lang="en">
<head>
	<meta http-equiv="content-type" content="text/html; charset=utf-8" />
	<meta name="description" content="Quoha - A Quaint Static Web Site Generator" />
	<meta name="keywords" content="quoha,static web,template generator,html" />
	<meta name="author" content="Michael Henderson" />
	<link rel="stylesheet" type="text/css" href="/css/andreas08.css" title="andreas08" media="screen,projection" />
	<title>Quoha - [[pageTitle]]</title>
</head>

<body>
<div id="container" >
	<div id="header">
		<h1>Quoha</h1>
		<h2>a quaint framework for static websites</h2>
	</div>

	<div id="navigation">
		[[pageTabs]]
	</div><!-- navigation -->

	<div id="content">
		[[pageBody]]

		<div class="splitcontentleft">
			[[pageContentLeft]]
		</div><!-- splitcontentleft -->

		<div class="splitcontentright">
			[[pageContentRight]]
		</div><!-- splitcontentright -->
	</div><!-- content -->

	<div id="subcontent">
		[[pageSubContent]]
	</div><!-- subcontent -->

	<div id="footer">
		[[pageFooter]]
	</div>

	</div>
</body>
</html>
