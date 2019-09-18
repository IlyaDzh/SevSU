var el = document.getElementById('drop');
var dropdownList = document.getElementById('menu-list');

el.addEventListener('mouseover', () => {
    dropdownList.classList.add('d-block');
});

el.addEventListener('mouseout', () => {
    dropdownList.classList.remove('d-block');
});