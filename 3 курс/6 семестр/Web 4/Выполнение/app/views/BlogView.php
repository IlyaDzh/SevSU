<script src="/public/js/date.js"></script>
<script src="/public/js/sendMessage.js"></script>

<section class="content container">
    <h2 class="mb-4">Блог</h2>
    <div class='posts-block'>
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
        <?php
                        if ($_SESSION["isUser"]) {
        ?>
                            <div class="card-comment__add">
                                <div class="input-group">
                                    <input type="text" class="form-control" name="comment" data-id=<?= $post['id'] ?> placeholder="Введите ваш комментарий" aria-describedby="send-btn" autocomplete="off">
                                    <div class="input-group-append">
                                        <button 
                                            class="btn btn-outline-secondary" 
                                            type="button" 
                                            id="send-btn"
                                            onClick="createScript(<?= $post['id'] ?>, '<?= $_SESSION["userFullname"] ?>')"
                                        >
                                            Отправить
                                        </button>
                                    </div>
                                </div>
                            </div>
        <?php
                        }
        ?>
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
                    href="/blog/index/?page=<?= $data['current_page'] - 1 == 0 ? 1 : $data['current_page'] - 1?>"
                >
                    Предыдущая
                </a>
            </li>
            <?php
                for ($i = 1; $i <= $data['total_pages']; $i++) {
                    if (!($i == $data['current_page'])) {
                        echo '
                            <li class="page-item">
                                <a class="page-link" href="/blog/index/?page='.$i.'">'.$i.'</a>
                            </li>
                        ';
                    } else {
                        echo '
                            <li class="page-item active">
                                <a class="page-link" href="/blog/index/?page='.$i.'">'.$i.'</a>
                            </li>
                        ';
                    }
                }
            ?>
            <li class="page-item">
                <a 
                    class="page-link" 
                    href="/blog/index/?page=<?= $data['current_page'] + 1 > $data['total_pages'] ? $data['total_pages'] : $data['current_page'] + 1 ?>"
                >
                    Следующая
                </a>
            </li>
        </ul>
    </nav>
</section>