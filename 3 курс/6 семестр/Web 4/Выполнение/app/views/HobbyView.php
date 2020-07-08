<section class="list-anchor content container">
    <h3 class="text-center">Мои интересы</h3>
    <ul class="nav justify-content-center">
        <?php 
            foreach($data as $row) {
                echo '
                    <li class="nav-item">
                        <a class="nav-link active" href="#'.$row['id'].'">
                            '.$row['title'].'
                        </a>
                    </li>
                ';
            }
        ?>
    </ul>
</section>

<section class="container">
    <?php
        $i = 0;
        foreach($data as $row) {
            $reverse = ++$i % 2 == 0 ? 'flex-row-reverse' : '';
            echo '
                <div class="'.$row['id'].' pt-6" id='.$row['id'].'>
                    <div class="row align-items-center '. $reverse .'">
                        <div class="col-md-4">
                            <img src="/public/img/'.$row['picture'].'" class="rounded img-fluid" alt="">
                        </div>
                        <div class="col-md-8">
                            <h1 class="about__title mb-4">
                                '.$row['title'].'
                            </h1>
                            <p class="about__desc">
                                '.$row['desc'].'
                            </p>
                        </div>
                    </div>
                </div>
            ';
        }
    ?>
</section>