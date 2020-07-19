const editBtn = document.getElementsByClassName("edit-btn");
const modal = document.querySelector(".modal");
const container = modal.querySelector(".container");

const modalTitle = document.getElementById("editTitle");
const modalMessage = document.getElementById("editMessage");
const modalErrorBlock = document.getElementById("modalErrorBlock");

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
            message: e.currentTarget.getAttribute("data-message")
        };
        modalTitle.value = currentPost.title;
        modalMessage.value = currentPost.message;
        modal.classList.remove("hidden");
        document.getElementById("saveBtn").addEventListener("click", saveChanges);
    });
}

const saveChanges = () => {
    const xmlString = "<profile>" +
    "  <id>" + currentPost.id + "</id>" +
    "  <title>" + modalTitle.value + "</title>" +
    "  <message>" + modalMessage.value + "</message>" +
    "</profile>";

    let xmlhttp = new XMLHttpRequest();

    xmlhttp.open("POST", "http://web/admin/editblog/edit", true);
    xmlhttp.setRequestHeader("Content-Type", "text/xml; charset=UTF-8");
    xmlhttp.send(xmlString);

    xmlhttp.onreadystatechange = () => {
        if (xmlhttp.readyState == 4) {
            if (xmlhttp.status == 200) {
                const data = JSON.parse(xmlhttp.response);
                modalErrorBlock.innerHTML = "";
                if (data.length) {
                    data.forEach(err => {
                        const errorDiv = document.createElement("p");
                        errorDiv.className = "result-block__item error";
                        errorDiv.innerHTML = err;
                        modalErrorBlock.appendChild(errorDiv);
                    });
                } else {
                    const currentBtn = document.querySelectorAll(
                        `.btn.edit-btn[data-id="${currentPost.id}"]`
                    )[0];
                    const title = currentBtn.parentNode.getElementsByTagName(
                        "h5"
                    )[0];
                    const text = currentBtn.parentNode.getElementsByTagName("p")[0];
                    title.innerHTML = modalTitle.value;
                    text.innerHTML = modalMessage.value;
                    currentBtn.setAttribute("data-title", modalTitle.value);
                    currentBtn.setAttribute("data-message", modalMessage.value);
                    modal.classList.add("hidden");
                }
            }
        }
    };
};
