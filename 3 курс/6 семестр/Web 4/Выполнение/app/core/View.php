<?php

class View {
	function render($content_view, $title, $data = null, $template_view = 'LayoutView.php') {
		include 'app/views/' . $template_view;
	}
}