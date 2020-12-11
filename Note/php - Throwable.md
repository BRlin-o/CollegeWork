## PHP - Throwable

### Throwable
- Error
  - ArithmeticError
    - DivisionByZeroError
  - AssertionError
  - CompileError
    - ParseError
  - TypeError
    - ArgumentCountError
- Exception
  - ClosedGeneratorException
  - DOMException
  - ErrorException
  - IntlException
  - JsonException
  - LogicException
    - BadFunctionCallException
      - BadMethodCallException
    - DomainException
    - InvalidArgumentException
    - LengthException
    - OutOfRangeException
  - PharException
  - ReflectionException
  - RuntimeException
    - OutOfBoundsException
    - OverflowException
    - PDOException
    - RangeException
    - UnderflowException
    - UnexpectedValueException
  - SodiumException

#### Error (```class Error extends Throwsable```)
```Error```主要為```php```執行產生錯誤時所發出，終於在```PHP 7```可以被捕獲並處裡。

一般而言，開發者不需要自行開發```Error Class```，只要捕獲即可用內建的```Error Class```中提出並解釋。

#### Exception (```class Exception extends Throwable```)
```Exception```主要用於提出例外狀況，在```php```中還可以設計自己的```Exception Class```。

```Exception```主要分成```RuntimeException```及```LogicException```兩種。
