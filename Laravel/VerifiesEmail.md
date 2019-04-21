## VerifiesEmails
```php
public function verify(Request $request) 
{
    if (! $request->hasValidSignature()) {
        abort(401);
    }

    $user = User::findOrFail($request->get('user_id'));

    if ($user->markEmailAsVerified()) {
        event(new Verified($user));
    }

    return redirect($this->redirectPath())->with('verified', true);
}

public function resend(Request $request)
{
    if ($request->user()->hasVerifiedEmail()) {
        return redirect($this->redirectPath());
    }

    $request->user()->sendEmailVerificationNotification();

    return response()->json();
}
```
