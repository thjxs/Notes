# ListNode

```js
let list = {
    next: null,
    value: -1
}

function reverse(list) {
    let res = null
    let tmp = list
    while(list !== null) {
        list = list.next
        tmp.next = res
        res = tmp
        tmp = list
    }
    return res
}

function middle(list) {
    let fast = list
    let slow = list
    while(fast && fast.next) {
        fast = fast.next.next
        slow = slow.next
    }
    return slow
}

function isPalindrome(list) {
    if(list === null || list.next === null) {
        return true
    }

    let fast = list
    let slow = list

    while(fast.next !== null && fast.next.next !== null) {
        fast = fast.next.next
        slow = slow.next
    }
    slow.next = reverse(slow.next)
    slow = slow.next
    while(slow !== null) {
        if(list.value !== slow.value) {
            return false
        }
        list = list.next
        slow = slow.next
    }

    return true
}

```