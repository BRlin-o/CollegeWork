### 運作優化
- yield

### 物件轉換
- json
- Serializable

### 指引呼叫
```php
$a = function () { echo 'hello world'; }
$a instanceof Closure; // true
```

### 例外處裡
- Throwsable
- Error
- Exception

### 功能維護
- 單元測試(PHPUnit、Behat、Codeception)

### 載入耗時
```php
var_dump(realpath_cache_size())
```