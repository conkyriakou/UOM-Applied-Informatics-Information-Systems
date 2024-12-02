'use strict';

document.addEventListener('DOMContentLoaded', (event) => {
    let score = 0;

    function updateScore(points) {
        score += points;
        document.getElementById('score').textContent = score;
    }

    document.getElementById('b1').addEventListener('click', () => {
        updateScore(1);
    });

    document.getElementById('b2').addEventListener('click', () => {
        updateScore(2);
    });

    document.getElementById('b3').addEventListener('click', () => {
        updateScore(3);
    });
});