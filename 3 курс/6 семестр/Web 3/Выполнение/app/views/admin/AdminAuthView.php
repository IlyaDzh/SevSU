<section class="content container">
    <div class="row justify-content-center">
        <div class="col-lg-4 text-center">
            <h3 class="mb-4">Вход в панель администратора</h3>
            <form action="/admin/auth/login" method="POST">
                <div class="form-group">
                    <input type="text" class="form-control tooltip-input" name="login" value="<?if (isset($_POST["login"])) echo $_POST["login"];?>" placeholder="Введите логин" autocomplete="off">
                </div>
                <div class="form-group">
                    <input type="password" class="form-control tooltip-input" name="password" value="<?if (isset($_POST["password"])) echo $_POST["password"];?>" placeholder="Введите пароль">
                </div>
                <button class="btn btn-primary btn-block" type="submit">Войти</button>
            </form>
            <div class='result-block'>
                <?php 
                    if (isset($data['errors'])) {
                        if (count($data['errors']) > 0) {
                            foreach ($data['errors'] as $key => $item) {
                                echo "<p class='result-block__item error'>$item</p>";
                            }
                        }
                    }
                    if (isset($data['login']) && !$data['login']) {
                        echo "<p class='result-block__item error'>Неверный логин или пароль</p>";
                    }
                ?>
            </div>
        </div>
    </div>
</section>