function createScript(id, fullname) {
    const input = document.querySelector(`.form-control[data-id='${id}']`);

    if (input.value === "") return;

    const newScript = document.createElement("script");

    const date = new Date().format("yyyy-MM-dd h:mm:ss");

    newScript.src =
        "/blog/add/?id_post=" +
        id +
        "&fullname=" +
        fullname +
        "&comment=" +
        input.value +
        "&date=" +
        date;

    document.getElementsByTagName("body")[0].appendChild(newScript);
}

function addComment(data) {
    const input = document.querySelector(`.form-control[data-id='${data.id}']`);

    const numberComments = input.parentNode.parentNode.parentNode.querySelector(
        ".card-comment__title"
    );
    numberComments.innerHTML = parseInt(numberComments.innerHTML) + 1 + " Комментариев";

    const commentContainer = input.parentNode.parentNode.parentNode.querySelector(
        ".card-comment__container"
    );
    commentContainer.insertAdjacentHTML(
        "afterbegin",
        `<div class="comment-item"><div class="d-flex"><div class="comment-item__name">${data.fullname},</div><div class="comment-item__date">${data.date}</div></div><div class="comment-item__text">${data.comment}</div></div>`
    );

    input.value = "";
}
