// Render items in cart
window.onload = function() {
  let cart = JSON.parse(window.localStorage.getItem("cart"));

  if (cart) {
    let itemsHTML = cart.map(item => {
      return `<tr class="item-row"><td><img src="${
        item.image
      }" alt="item-image" id="image-${item.id}" /></td><td>${
        item.name
      }</td><td>${item.number}</td></tr>`;
    });

    let cartTable = document.getElementById("cart-table");
    cartTable.innerHTML = itemsHTML;
    console.log(cartTable);
  }
};

function submitOrder() {}
