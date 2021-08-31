# Literal Types

```text
interface ValidationSuccess {
    isValid: true;
    reason: null;
}

interface ValidationFailure {
    isValid: false;
    reason: string;
}
type ValidationResult = ValidationSuccess | ValidationFailure
```
