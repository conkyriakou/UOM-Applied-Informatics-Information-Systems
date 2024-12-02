document.addEventListener('DOMContentLoaded', () => {
    const box = document.getElementById('box');
    const buttons = {
        b1: document.getElementById('b1'),
        b2: document.getElementById('b2'),
        b3: document.getElementById('b3'),
        b4: document.getElementById('b4')
    };

    const corners = {
        b1: 'borderTopLeftRadius',
        b2: 'borderTopRightRadius',
        b3: 'borderBottomLeftRadius',
        b4: 'borderBottomRightRadius'
    };

    const toggleCorner = (buttonId) => {
        const corner = corners[buttonId];
        const currentRadius = box.style[corner];
        box.style[corner] = currentRadius === '25px' ? '0' : '25px';
    };

    for (const buttonId in buttons) {
        buttons[buttonId].addEventListener('click', () => toggleCorner(buttonId));
    }
});