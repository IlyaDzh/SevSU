const token = document
    .querySelector('meta[name="csrf-token"]')
    .getAttribute("content");

const editBtn = document.getElementsByClassName("edit-btn");
const modal = document.querySelector(".modal");
const container = modal.querySelector(".container");

const modalTitle = document.getElementById("editTitle");
const modalMessage = document.getElementById("editMessage");
const modalErrorBlock = document.getElementById("modalErrorBlock");
const saveButton = document.getElementById("saveBtn");

let currentPost = {};

modal.addEventListener("click", e => {
    if (e.target !== modal && e.target !== container) return;
    modal.classList.add("hidden");
});

for (let i = 0; i < editBtn.length; i++) {
    editBtn[i].addEventListener("click", e => {
        currentPost = {
            id: e.currentTarget.getAttribute("data-id"),
            title: e.currentTarget.getAttribute("data-title"),
            text: e.currentTarget.getAttribute("data-text")
        };
        modalTitle.value = currentPost.title;
        modalMessage.value = currentPost.text;
        modal.classList.remove("hidden");
    });
}

const fetchEditingPost = () => {
    const request = new Request("/post/update", {
        method: "PATCH",
        body: JSON.stringify({
            id: currentPost.id,
            title: modalTitle.value,
            text: modalMessage.value
        }),
        headers: new Headers({
            "Content-Type": "application/json",
            "X-CSRF-TOKEN": token
        })
    });

    fetch(request).then(() => {
        const currentBtn = document.querySelectorAll(
            `.btn.edit-btn[data-id="${currentPost.id}"]`
        )[0];
        const title = currentBtn.parentNode.getElementsByTagName("h5")[0];
        const text = currentBtn.parentNode.getElementsByTagName("p")[0];
        title.innerHTML = modalTitle.value;
        text.innerHTML = modalMessage.value;
        currentBtn.setAttribute("data-title", modalTitle.value);
        currentBtn.setAttribute("data-text", modalMessage.value);
        modal.classList.add("hidden");
    });
};

saveButton.addEventListener("click", fetchEditingPost);
