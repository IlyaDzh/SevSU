const dropdownLink = document.getElementById("drop");
const dropdownList = document.getElementById("menu-list");

dropdownLink.addEventListener("mouseover", () => {
    dropdownList.classList.add("d-block");
});

dropdownLink.addEventListener("mouseout", () => {
    dropdownList.classList.remove("d-block");
});
