<div class="popup_bg" id="img-bg"></div>

<section class="content container">
    <div class="row">
    
        <?php
            $size = ceil(count($data) / 3);
            $array_result = array_chunk($data, $size);
            foreach($array_result as $chunk) {
                echo '<div class="col-md-4">';
                foreach($chunk as $item) {
                    echo '
                        <div class="img-elem">
                            <div class="img-wrapper rounded">
                                <img class="img-fluid rounded inner-img" src="/public/img/photo/'.$item['img'].'" title='.$item['title'].' />
                            </div>
                            <h5 class="photo__subtitle">'.$item['title'].'</h5>
                        </div>
                    ';
                }
                echo '</div>';
            }
        ?>

    </div>
</section>

<div class="popup unselectable" id="popup-main">
    <img class="popup_img rounded" id="img-container" src="" alt="">
</div>

<div class="control-block unselectable" id="control">
    <button class="control__btn" id="btn__left">&lt;</button>
    <span id="control__title">title</span>
    <button class="control__btn" id="btn__right">&gt;</button>
</div>

<script src="/public/js/openPhoto.js"></script>