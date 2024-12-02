document.querySelector('.submit').addEventListener('click', function() {
    const heightValue = document.getElementById('left').value;
    const widthValue = document.getElementById('bottom').value;

    // Validation: Ensure values are between 50 and 200
    if (heightValue >= 50 && heightValue <= 200 && widthValue >= 50 && widthValue <= 200) {
        document.querySelector('.myBox').style.height = heightValue + 'px';
        document.querySelector('.myBox').style.width = widthValue + 'px';
    } else {
        alert('Please enter values between 50 and 200.');
    }
});
