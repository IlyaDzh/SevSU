<section class="content container">
    <h2 class="mb-4">Редактор блога</h2>
    <form action="/admin/editblog/add" method="POST" enctype="multipart/form-data">
        <div class="form-group">
            <input type="text" class="form-control tooltip-input" name="title" value="<?if (isset($_POST["title"])) echo $_POST["title"];?>"
                placeholder="Тема сообщения" autocomplete="off">
        </div>
        <div class="form-group">
            <div class="custom-file">
                <input type="file" name="file" accept=".png, .jpeg, .jpg" class="form-control" id="uploadInput" aria-describedby="uploadInputBtn">
                <label class="custom-file-label" for="uploadInput">Загрузите изображение</label>
            </div>
        </div>
        <div class="form-group">
            <textarea class="form-control" name="message" rows="4" placeholder="Введите сообщение"><?if (isset($_POST["message"])) echo $_POST["message"];?></textarea>
        </div>
        <button class="btn btn-primary" type="submit">Добавить</button>
    </form>

    <div class='result-block mb-4'>
        <?php 
            if (isset($data['errors'])) {
                if (count($data['errors']) > 0) {
                    foreach ($data['errors'] as $key => $item) {
                        echo "<p class='result-block__item error'>$item</p>";
                    }
                } else {
                    echo "<p class='result-block__item success'>Тема успешно была создана</p>";
                }
            }
        ?>
    </div>

    <div class='posts-block'>
        <h5 class='mb-3'>Темы:</h5>
        <?php 
            $i = 0;
            if (isset($data['posts']) && count($data['posts']) > 0) {
                foreach ($data['posts'] as $post) {
        ?>
                    <div class="card card-blog mb-4">
                        <div class="row no-gutters">
                            <div class="col-md-4">
                                <img src=<?= $post['image'] ? $post['image'] : '/public/img/not-found.png' ?> class="card-img">
                            </div>
                            <div class="col-md-8 d-flex flex-column">
                                <div class="card-body">
                                    <h5 class="card-title"><?= $post['title'] ?></h5>
                                    <p class="card-text"><?= $post['text'] ?></p>
                                    <button 
                                        class="btn edit-btn"
                                        type="button"
                                        data-id='<?= $post['id'] ?>'
                                        data-title='<?= $post['title'] ?>'
                                        data-message='<?= $post['text'] ?>'
                                    >
                                        <img src="/public/img/edit.svg" />
                                    </button>
                                </div>
                                <div class="card-footer">
                                    <small class="text-muted"><?= $post['date'] ?></small>
                                </div>
                            </div>
                        </div>
                        <div class="card-comment">
                            <h6 class="card-comment__title">
                                <?= count($data['comments'][$i]) ?> Комментариев
                            </h6>
                            <div class="card-comment__container">
        <?php
                            foreach ($data['comments'][$i] as $comment) {
        ?>
                                <div class="comment-item">
                                    <div class="d-flex">
                                        <div class="comment-item__name"><?= $comment['fullname'] ?>,</div>
                                        <div class="comment-item__date"><?= $comment['date'] ?></div>
                                    </div>
                                    <div class="comment-item__text"><?= $comment['comment'] ?></div>
                                </div>
        <?php
                            }
        ?>
                            </div>
                        </div>
                    </div>
        <?php
                    $i += 1;
                }
            } else {
                echo "<div class='font-italic'>Тем нет</div>";
            }
        ?>
    </div>

    <nav class="mt-3 <?= $data['total_pages'] == 0 ? 'd-none' : '' ?>">
        <ul class="pagination justify-content-center">
            <li class="page-item">
                <a 
                    class="page-link" 
                    href="/admin/editblog/index/?page=<?= $data['current_page'] - 1 == 0 ? 1 : $data['current_page'] - 1?>"
                >
                    Предыдущая
                </a>
            </li>
            <?php
                for ($i = 1; $i <= $data['total_pages']; $i++) {
                    if (!($i == $data['current_page'])) {
                        echo '
                            <li class="page-item">
                                <a class="page-link" href="/admin/editblog/index/?page='.$i.'">'.$i.'</a>
                            </li>
                        ';
                    } else {
                        echo '
                            <li class="page-item active">
                                <a class="page-link" href="/admin/editblog/index/?page='.$i.'">'.$i.'</a>
                            </li>
                        ';
                    }
                }
            ?>
            <li class="page-item">
                <a 
                    class="page-link" 
                    href="/admin/editblog/index/?page=<?= $data['current_page'] + 1 > $data['total_pages'] ? $data['total_pages'] : $data['current_page'] + 1 ?>"
                >
                    Следующая
                </a>
            </li>
        </ul>
    </nav>

    <div class="modal hidden">
        <div class="container">
            <div class="body">
                <h4 class="text-center mb-4">Редактирование</h4>
                <form>
                    <div class="form-group">
                        <input id="editTitle" type="text" class="form-control tooltip-input" placeholder="Тема сообщения" autocomplete="off">
                    </div>
                    <div class="form-group">
                        <textarea id="editMessage" class="form-control" rows="4" placeholder="Введите сообщение"></textarea>
                    </div>
                    <button id="saveBtn" class="btn btn-primary w-100" type="button">Сохранить</button>
                </form>
                <div id="modalErrorBlock" class="mt-3"></div>
            </div>
        </div>
    </div>

    <script>
        const inputFile = document.getElementById("uploadInput");
        const inputLabel = document.getElementsByClassName("custom-file-label")[0];
        inputFile.addEventListener("change", e => {
            inputLabel.innerHTML = e.target.files[0].name;
        });
    </script>
     <script src="/public/js/editBlog.js"></script>
</section>