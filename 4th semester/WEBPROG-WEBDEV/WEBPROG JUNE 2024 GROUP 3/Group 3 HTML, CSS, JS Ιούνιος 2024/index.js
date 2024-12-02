// index.js

// Food item prices
const prices = {
    clubSandwich: 5,
    spaghetti: 6
};

// Store selected items
let selectedItems = {
    clubSandwich: false,
    spaghetti: false
};

// Track total cost
let totalCost = 0;

// Get references to DOM elements
const clubSandwichButton = document.getElementById('clubSandwich');
const spaghettiButton = document.getElementById('spaghetti');
const totalCostDisplay = document.getElementById('totalCost');
const portionsInput = document.getElementById('portions');
const applyButton = document.getElementById('apply');

// Toggle item selection
clubSandwichButton.addEventListener('click', function() {
    selectedItems.clubSandwich = !selectedItems.clubSandwich;
    updateSelection(clubSandwichButton, selectedItems.clubSandwich);
});

spaghettiButton.addEventListener('click', function() {
    selectedItems.spaghetti = !selectedItems.spaghetti;
    updateSelection(spaghettiButton, selectedItems.spaghetti);
});

// Update button styles based on selection
function updateSelection(button, isSelected) {
    if (isSelected) {
        button.classList.add('active');
    } else {
        button.classList.remove('active');
    }
}

// Handle "Apply" button click
applyButton.addEventListener('click', function() {
    let portions = parseInt(portionsInput.value, 10);

    // Validate input (positive integer)
    if (isNaN(portions) || portions <= 0) {
        alert('Παρακαλώ εισάγετε έναν έγκυρο αριθμό μερίδων.');
        portionsInput.value = 1;
        return;
    }

    // Calculate total cost based on selected items and portions
    totalCost = 0;

    if (selectedItems.clubSandwich) totalCost += prices.clubSandwich;
    if (selectedItems.spaghetti) totalCost += prices.spaghetti;

    totalCost *= portions;
    totalCostDisplay.textContent = totalCost;
});
