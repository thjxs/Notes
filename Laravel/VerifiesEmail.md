# VerifiesEmails

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

## Traits

```php
trait MustVerifyEmail
{
    public function sendEmailVerificationNotification()
    {
        $this->notify(new VerifyEmail);
    }

    public function markEmailAsVerified()
    {
        return $this->forceFill([
            'email_verified_at' => $this->freshTimestamp()
        ])->save();
    }

    public function hasVerifiedEmail()
    {
        return ! is_null($this->email_verified_at);
    }

    /**
     * Generate signed url for current user
     * @return string
     */
    protected function verificationUrl()
    {
        return URL::temporarySignedRoute('verification.verify', now()->addMinutes(30), ['user_id' => $this->getKey()]);
    }
}
```
