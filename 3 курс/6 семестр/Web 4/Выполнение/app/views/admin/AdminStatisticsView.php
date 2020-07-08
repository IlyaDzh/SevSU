<section class="content container">
    <h2 class="mb-4">Статистика</h2>
    <div class='statistics-block'>
        <table class="table table-sm table-hover">
            <thead class="thead-light">
                <tr>
                    <th scope="col">Страница</th>
                    <th scope="col">IP</th>
                    <th scope="col">Host</th>
                    <th scope="col">Браузер</th>
                    <th scope="col">Дата</th>
                </tr>
            </thead>
            <tbody>
            <?php 
                if (isset($data['statistics']) && count($data['statistics']) > 0) {
                    foreach ($data['statistics'] as $statistics_item) {
                        echo '
                            <tr>
                                <td>'.$statistics_item['page'].'</td>
                                <td>'.$statistics_item['ip'].'</td>
                                <td>'.$statistics_item['host'].'</td>
                                <td>'.$statistics_item['browser'].'</td>
                                <td>'.$statistics_item['date'].'</td>
                            </tr>
                        ';
                    }
                } else {
                    echo "<tr><td class='font-italic' colspan='5'>Статистики нет</td></tr>";
                }
            ?>
            </tbody>
        </table>
    </div>
    <nav class="mt-3 <?= $data['total_pages'] == 0 ? 'd-none' : '' ?>">
        <ul class="pagination justify-content-center">
            <li class="page-item">
                <a 
                    class="page-link" 
                    href="/admin/statistics/index/?page=<?= $data['current_page'] - 1 == 0 ? 1 : $data['current_page'] - 1?>"
                >
                    Предыдущая
                </a>
            </li>
            <?php
                for ($i = 1; $i <= $data['total_pages']; $i++) {
                    if (!($i == $data['current_page'])) {
                        echo '
                            <li class="page-item">
                                <a class="page-link" href="/admin/statistics/index/?page='.$i.'">'.$i.'</a>
                            </li>
                        ';
                    } else {
                        echo '
                            <li class="page-item active">
                                <a class="page-link" href="/admin/statistics/index/?page='.$i.'">'.$i.'</a>
                            </li>
                        ';
                    }
                }
            ?>
            <li class="page-item">
                <a 
                    class="page-link" 
                    href="/admin/statistics/index/?page=<?= $data['current_page'] + 1 > $data['total_pages'] ? $data['total_pages'] : $data['current_page'] + 1 ?>"
                >
                    Следующая
                </a>
            </li>
        </ul>
    </nav>
</section>