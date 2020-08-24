-- Удалить старую базу и создать новую
DROP DATABASE IF EXISTS lab4;
CREATE DATABASE lab4;

-- Использовать созданную базу
USE lab4;

-- blogs (id, title, posts_count)

-- Создать таблицу без партицирования
CREATE TABLE IF NOT EXISTS `transactions_no_part_200` (
    `id` INTEGER NOT NULL AUTO_INCREMENT,
    `title` VARCHAR(20) NOT NULL DEFAULT 'this title',
    `posts_count` INTEGER NOT NULL,
    PRIMARY KEY (`id`)
) ENGINE = InnoDB;

-- Создать таблицу с партицированием
CREATE TABLE IF NOT EXISTS `transactions_part_200` (
    `id` INTEGER NOT NULL AUTO_INCREMENT,
    `title` VARCHAR(20) NOT NULL DEFAULT 'this title',
    `posts_count` INTEGER NOT NULL,
    PRIMARY KEY (`id`)
) ENGINE = InnoDB
PARTITION BY HASH(`id`)
PARTITIONS 4;

-- Создать таблицу без партицирования
CREATE TABLE IF NOT EXISTS `transactions_no_part_700` (
    `id` INTEGER NOT NULL AUTO_INCREMENT,
    `title` VARCHAR(20) NOT NULL DEFAULT 'this title',
    `posts_count` INTEGER NOT NULL,
    PRIMARY KEY (`id`)
) ENGINE = InnoDB;

-- Создать таблицу с партицированием
CREATE TABLE IF NOT EXISTS `transactions_part_700` (
    `id` INTEGER NOT NULL AUTO_INCREMENT,
    `title` VARCHAR(20) NOT NULL DEFAULT 'this title',
    `posts_count` INTEGER NOT NULL,
    PRIMARY KEY (`id`)
) ENGINE = InnoDB
PARTITION BY HASH(`id`)
PARTITIONS 4;

-- Создать таблицу без партицирования
CREATE TABLE IF NOT EXISTS `transactions_no_part_1300` (
    `id` INTEGER NOT NULL AUTO_INCREMENT,
    `title` VARCHAR(20) NOT NULL DEFAULT 'this title',
    `posts_count` INTEGER NOT NULL,
    PRIMARY KEY (`id`)
) ENGINE = InnoDB;

-- Создать таблицу с партицированием
CREATE TABLE IF NOT EXISTS `transactions_part_1300` (
    `id` INTEGER NOT NULL AUTO_INCREMENT,
    `title` VARCHAR(20) NOT NULL DEFAULT 'this title',
    `posts_count` INTEGER NOT NULL,
    PRIMARY KEY (`id`)
) ENGINE = InnoDB
PARTITION BY HASH(`id`)
PARTITIONS 4;

-- Создать таблицу без партицирования
CREATE TABLE IF NOT EXISTS `transactions_no_part_1900` (
    `id` INTEGER NOT NULL AUTO_INCREMENT,
    `title` VARCHAR(20) NOT NULL DEFAULT 'this title',
    `posts_count` INTEGER NOT NULL,
    PRIMARY KEY (`id`)
) ENGINE = InnoDB;

-- Создать таблицу с партицированием
CREATE TABLE IF NOT EXISTS `transactions_part_1900` (
    `id` INTEGER NOT NULL AUTO_INCREMENT,
    `title` VARCHAR(20) NOT NULL DEFAULT 'this title',
    `posts_count` INTEGER NOT NULL,
    PRIMARY KEY (`id`)
) ENGINE = InnoDB
PARTITION BY HASH(`id`)
PARTITIONS 4;

-- Создать процедуру для генерации случайных данных
DELIMITER //
CREATE PROCEDURE `generate_data_200` (IN items_count INT)
BEGIN
    DECLARE i INT DEFAULT 0;
    WHILE i < items_count DO
        INSERT INTO `transactions_no_part_200` (`posts_count`) VALUES (RAND() * 200);
        SET i = i + 1;
    END WHILE;
    -- Скопировать те же данные в партицированную таблицу
    INSERT INTO `transactions_part_200`
        SELECT * FROM `transactions_no_part_200`;
END//
DELIMITER ;

-- Создать процедуру для генерации случайных данных
DELIMITER //
CREATE PROCEDURE `generate_data_700` (IN items_count INT)
BEGIN
    DECLARE i INT DEFAULT 0;
    WHILE i < items_count DO
        INSERT INTO `transactions_no_part_700` (`posts_count`) VALUES (RAND() * 700);
        SET i = i + 1;
    END WHILE;
    -- Скопировать те же данные в партицированную таблицу
    INSERT INTO `transactions_part_700`
        SELECT * FROM `transactions_no_part_700`;
END//
DELIMITER ;

-- Создать процедуру для генерации случайных данных

DELIMITER //
CREATE PROCEDURE `generate_data_1300` (IN items_count INT)
BEGIN
DECLARE i INT DEFAULT 0;
    WHILE i < items_count DO
        INSERT INTO `transactions_no_part_1300` (`posts_count`) VALUES (RAND() * 1300);
        SET i = i + 1;
    END WHILE;
    -- Скопировать те же данные в партицированную таблицу
    INSERT INTO `transactions_part_1300`
        SELECT * FROM `transactions_no_part_1300`;
END//
DELIMITER ;

-- Создать процедуру для генерации случайных данных
DELIMITER //
CREATE PROCEDURE `generate_data_1900` (IN items_count INT)
BEGIN
    DECLARE i INT DEFAULT 0;
    WHILE i < items_count DO
        INSERT INTO `transactions_no_part_1900` (`posts_count`) VALUES (RAND() * 1900);
        SET i = i + 1;
    END WHILE;
    -- Скопировать те же данные в партицированную таблицу
    INSERT INTO `transactions_part_1900`
        SELECT * FROM `transactions_no_part_1900`;
END//
DELIMITER ;

-- Заполнить таблицу данными
CALL generate_data_200(200);
CALL generate_data_700(700);
CALL generate_data_1300(1300);
CALL generate_data_1900(1900);

-- Удалить процедуру
DROP PROCEDURE `generate_data_200`;
DROP PROCEDURE `generate_data_700`;
DROP PROCEDURE `generate_data_1300`;
DROP PROCEDURE `generate_data_1900`;