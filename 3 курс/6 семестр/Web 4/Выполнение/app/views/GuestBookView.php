<section class="content container">
    <form action="/guestbook/create" method="POST">
        <div class="form-group">
            <input type="text" class="form-control tooltip-input" name="fullname" value="<?if (isset($_POST["fullname"])) echo $_POST["fullname"];?>"
                title="Фамилия Имя Отчество" placeholder="Введите ваше ФИО" autocomplete="off">
        </div>
        <div class="form-group">
            <input type="text" class="form-control tooltip-input" name="Email" title="Пример: ivanov@gmail.com"
                value="<?if (isset($_POST["Email"])) echo $_POST["Email"];?>" 
                placeholder="Введите email" autocomplete="off">
        </div>
        <div class="form-group">
            <textarea class="form-control" name="review" rows="4" placeholder="Введите отзыв"><?if (isset($_POST["review"])) echo $_POST["review"];?></textarea>
        </div>
        <button class="btn btn-primary" type="submit">Отправить</button>
    </form>
    <div class='result-block'>
        <?php 
            if (isset($data['errors'])) {
                if (count($data['errors']) > 0) {
                    foreach ($data['errors'] as $key => $item) {
                        echo "<p class='result-block__item error'>$item</p>";
                    }
                } else {
                    echo "<p class='result-block__item success'>Отзыв был отправлен</p>";
                }
            }
        ?>
    </div>
    <div class='reviews-block'>
        <h5 class='mb-3'>Отзывы:</h5>
        <?php 
            if (isset($data['reviews']) && count($data['reviews']) > 0) {
                foreach ($data['reviews'] as $review) {
                    echo "
                        <div class='reviews-block__item'>
                            <div class='reviews__header'>
                                <b>$review[0]</b>, <i>$review[2]</i>
                            </div>
                            <div class='reviews__content'>$review[3]</div>
                        </div>
                    ";
                }
            } else {
                echo "<div class='font-italic'>Отзывов нет</div>";
            }
        ?>
    </div>
</section>