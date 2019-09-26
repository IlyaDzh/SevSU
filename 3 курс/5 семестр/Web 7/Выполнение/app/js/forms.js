var ClearContact, ClearTest, ValidContact, ValidTest, checkAns, checkEmpty, checkFio, checkMail, checkNum, checkSelect;

ClearTest = function() {
  var ans, fio, group, select;
  ans = document.forms[0].inputQ;
  fio = document.forms[0].inputFio;
  group = document.forms[0].inputGroup;
  select = document.forms[0].inputSelect;
  ans.classList.remove('is-invalid');
  fio.classList.remove('is-invalid');
  group.classList.remove('is-invalid');
  select.classList.remove('is-invalid');
  ans.classList.remove('is-valid');
  fio.classList.remove('is-valid');
  group.classList.remove('is-valid');
  select.classList.remove('is-valid');
};

ClearContact = function() {
  var date, email, fio, number, text;
  fio = document.forms[0].inputFio;
  number = document.forms[0].inputNum;
  date = document.forms[0].inputDate;
  email = document.forms[0].inputEmail;
  text = document.forms[0].inputText;
  number.classList.remove('is-invalid');
  fio.classList.remove('is-invalid');
  email.classList.remove('is-invalid');
  date.classList.remove('is-invalid');
  text.classList.remove('is-invalid');
  number.classList.remove('is-valid');
  fio.classList.remove('is-valid');
  email.classList.remove('is-valid');
  date.classList.remove('is-valid');
  text.classList.remove('is-valid');
};

ValidTest = function() {
  if (checkFio() && checkEmpty(document.forms[0].inputGroup) && checkSelect() && checkAns()) {
    return true;
  } else {
    return false;
  }
};

ValidContact = function() {
  if (checkFio() && checkEmpty(document.forms[0].inputDate) && checkNum() && checkMail() && checkEmpty(document.forms[0].inputText)) {
    return true;
  } else {
    return false;
  }
};

checkMail = function() {
  var email;
  email = document.forms[0].inputEmail;
  if (!email.value.match(/[0-9a-z_]+@[0-9a-z_]+\.[a-z]{2,5}/i) || email.value === '') {
    email.classList.add('is-invalid');
    email.focus();
    return false;
  }
  email.classList.remove('is-invalid');
  email.classList.add('is-valid');
  return true;
};

checkAns = function() {
  var ans;
  ans = document.forms[0].inputQ;
  if (ans.value.match(/[0-9]+/) || ans.value === '') {
    $(ans).addClass('is-invalid');
    ans.focus();
    return false;
  }
  $(ans).removeClass('is-invalid');
  $(ans).addClass('is-valid');
  return true;
};

checkFio = function() {
  var fio, fioLength;
  fio = document.forms[0].inputFio;
  fioLength = fio.value.trim().split(/\s+/).length;
  if (fioLength !== 3 || fio.value.match(/[0-9]+/)) {
    $(fio).addClass('is-invalid');
    fio.focus();
    return false;
  }
  $(fio).removeClass('is-invalid');
  $(fio).addClass('is-valid');
  return true;
};

checkNum = function() {
  var number;
  number = document.forms[0].inputNum;
  if (!number.value.match(/^\+(7|3)\d{8,10}$/)) {
    $(number).addClass('is-invalid');
    number.focus();
    return false;
  }
  $(number).removeClass('is-invalid');
  $(number).addClass('is-valid');
  return true;
};

checkSelect = function() {
  var select;
  select = document.forms[0].inputSelect;
  if (select.selectedIndex === 0) {
    $(select).addClass('is-invalid');
    select.focus();
    return false;
  }
  $(select).removeClass('is-invalid');
  $(select).addClass('is-valid');
  return true;
};

checkEmpty = function(input) {
  if (input.value === '') {
    $(input).addClass('is-invalid');
    input.focus();
    return false;
  }
  $(input).removeClass('is-invalid');
  $(input).addClass('is-valid');
  return true;
};
