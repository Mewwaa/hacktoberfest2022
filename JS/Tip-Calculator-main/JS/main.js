const buttons = document.querySelectorAll(".btn");
const bill = document.querySelector("#Bill");
const reset = document.querySelector(".btn-reset");
const error = document.querySelector(".people small");
const people = document.querySelector("#People");

buttons[0].addEventListener("click", () => {
  check(5);
});
buttons[1].addEventListener("click", () => {
  check(10);
});
buttons[2].addEventListener("click", () => {
  check(15);
});
buttons[3].addEventListener("click", () => {
  check(25);
});
buttons[4].addEventListener("click", () => {
  check(50);
});
var customInput = document.getElementById("custom-input");
customInput.addEventListener("input", () => {
  var customInputValue = customInput.value;
  console.log(customInputValue);

  check(customInputValue);
});

function check(calcValue) {
  var peopleValue = document.getElementById("People").value;
  const people = document.querySelector("#People");
  if (peopleValue == 0) {
    error.classList = "error";
    people.style.border = "1px solid red";
  } else {
    error.classList = "small";
    people.style.border = "none";
    calculateTip(calcValue);
  }
}

// calculation function
function calculateTip(val) {
  var billValue = document.getElementById("Bill").value;

  var peopleValue = document.getElementById("People").value;

  const tipValue = document.querySelector(".tip-value");
  const totalValue = document.querySelector(".total-value");

  var tip = (billValue * val) / 100;
  var tipPerPerson = parseInt(tip) / parseInt(peopleValue);

  var totalAmount = parseInt(billValue) + parseInt(tip);

  var totalAmountPerPerson = parseInt(totalAmount) / parseInt(peopleValue);

  tipValue.textContent = "$" + tipPerPerson.toFixed(2);
  totalValue.textContent = "$" + totalAmountPerPerson.toFixed(2);
}
reset.addEventListener("click", () => {
  var customInput = document.getElementById("custom-input");
  const tipValue = document.querySelector(".tip-value");
  const totalValue = document.querySelector(".total-value");
  tipValue.textContent = "$0.00";
  totalValue.textContent = "$0.00";
  bill.value = "";
  people.value = "";
  customInput.value = "";
});
