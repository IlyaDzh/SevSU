<?php

class BaseActiveRecord {
	public static $pdo;
	protected static $tablename;
	protected static $dbfields = array();

	public function __construct() {
		if (!static::$tablename) {
			return;
		}
		static::setupConnection();
		static::getFields();
	}

	public static function getFields() {
		$stmt = static::$pdo->query("SHOW FIELDS FROM ".static::$tablename);
		while ($row = $stmt->fetch()) {
			static::$dbfields[$row['Field']] = $row['Type'];
		}
	}

	public static function setupConnection() {
		if (!isset(static::$pdo)) {
			try {
				static::$pdo = new PDO("mysql:dbname=web2; host=localhost; char-set=utf8", "root", "");
			} catch (PDOException $ex) {
				die("Ошибка подключения к БД: $ex");
			}
		}
	}

	public static function find($id) {
		$sql = "SELECT * FROM ".static::$tablename." WHERE id=$id";
		$stmt = static::$pdo->query($sql);
		$row = $stmt->fetch(PDO::FETCH_ASSOC);

		if (!$row) {
			return null;
		}

		$ar_obj = new static();
		foreach ($row as $key => $value) {
			$ar_obj ->$key = $value;
		}

		return $ar_obj;
	}

	public static function findAll() {
		static::setupConnection();
		static::getFields();

		$result = [];
		$sql = "SELECT * FROM ".static::$tablename;
		$stmt = static::$pdo->query($sql);
		
		while($row = $stmt->fetch(PDO::FETCH_ASSOC)) {
			array_push($result, $row);
		}

		return $result;
    }

	public static function findByPage($offset, $rowsPerPage) {
		static::setupConnection();

		$result = [];
        $sql = "SELECT * FROM ".static::$tablename." ORDER BY date DESC LIMIT ".$offset.", ".$rowsPerPage;
        $stmt = static::$pdo->query($sql);
		
		while($row = $stmt->fetch(PDO::FETCH_ASSOC)) {
			array_push($result, $row);
		}

		return $result;
    }
    
	public static function getCount() {
		static::setupConnection();

		$sql = "SELECT COUNT(*) FROM ".static::$tablename;
        $stmt = static::$pdo->query($sql);
        $result = $stmt->fetch(PDO::FETCH_ASSOC);

		return current($result);
	}

	public function save($data) {
		static::setupConnection();
		
		$values = implode("', '", $data);
		$values = '\'' . $values . '\'';
		$fields = implode("`, `", static::$dbfields);
		$fields = '`' . $fields . '`';
		
		$tablename1 = static::$tablename;
        $sql = "INSERT INTO $tablename1 ($fields) VALUES ($values)";
        $stmt = static::$pdo->query($sql);

		if ($stmt) {
			return $stmt->fetch(PDO::FETCH_ASSOC);
		} else {
			throw new Exception();
		}
	}

	public function delete() {
		$sql = "DELETE FROM ".static::$tablename." WHERE ID=".$this->id;
		$stmt = static::$pdo->query($sql);

		if ($stmt) {
			return $stmt->fetch(PDO::FETCH_ASSOC);
		} else {
			print_r(static::$pdo->errorInfo());
		}
	}
}
