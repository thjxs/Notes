## tabs
An switch tabs
using 'tab', 'tabpanel' mark tabs's role

The click event 
set all tab, tabpanel hidden

label
aria-selected, 
aria-controls indicate tabpanel's ID

```js
module.exports = function tabs (target) {
    var tabs;
    var panels;

    generateArrays();

    function generateArrays() {
        tabs = target.querySelectorAll('[role="tab"]');
        panels = target.querySelectorAll('[role="tabpanel"]');
    }

    for (let i = 0; i < tabs.length; i += 1) {
        addListeners(i);
    }

    function addListeners (index) {
        tabs[index].addListeners('click', clickEventListener);
        tabs[index].index = index
    }

    function clickEventListener (event) {
        var tab = event.target;
        activateTab(tab, false);
    }

    function activateTab(tab, setFocus) {
        setFocus = setFocus || true;

        deactivateTabs();

        tab.removeAttribute('tabindex');

        tab.setAttribute('aria-selected', 'true');

        var controls = tab.getAttribute('aria-controls');

        document.getElementById(controls).removeAttribute('hidden')

        if (setFocus) {
            tab.focus();
        }

    }

    function deactivateTabs () {
        for (let t = 0; t < tabs.length; t += 1) {
            tabs[t].setAttribute('tabindex', '-1');
            tabs[t].setAttribute('aria-selected', 'false');
        }

        for (let p = 0; p < panels.length; p += 1) {
            panels[p].setAttribute('hidden', 'hidden');
        }
    }
}
```
