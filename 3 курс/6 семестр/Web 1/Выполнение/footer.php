<?php 
    if ($footer_scripts) {
        foreach($footer_scripts as $script) {
            echo "<script src='public/js/$script'></script>";
        }
    }
?>

</body>

</html>