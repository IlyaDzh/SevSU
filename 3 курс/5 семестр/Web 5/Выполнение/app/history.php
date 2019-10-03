<?php     $title = 'Ilya D. | История';    include 'header.php'?><script src="js/history.js"></script><section class="container content"><h4>История текущего сеанса</h4><table class="table table-sm table-hover" id="localStorageTable"><thead class="thead-light"><tr><th scope="col">№</th><th scope="col">Страница</th><th scope="col">Посещений</th></tr></thead><tbody></tbody>
<script type="text/javascript">
//<![CDATA[

  getLocalStorageHistory();

//]]>
</script>
</table><h4 class="mt-4">История за все время</h4><table class="table table-sm table-hover" id="cookieTable"><thead class="thead-light"><tr><th scope="col">№</th><th scope="col">Страница</th><th scope="col">Посещений</th></tr></thead><tbody></tbody>
<script type="text/javascript">
//<![CDATA[

  getCookiesHistory();



//]]>
</script>
</table></section><script src="js/jquery-3.4.1.min.js"></script><script src="js/time.js"></script><script src="js/dropdown.js"></script>