const clearBtn = document.getElementsByClassName("btn-danger")[0];
const cover = document.getElementsByClassName("cover")[0];
const modal = document.getElementsByClassName("modal")[0];

modal.addEventListener("click", () => {
    modal.classList.remove("d-block");
    cover.classList.remove("d-block");
});

clearBtn.addEventListener("click", () => {
    modal.classList.add("d-block");
    cover.classList.add("d-block");
});
