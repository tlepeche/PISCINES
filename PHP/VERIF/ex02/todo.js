var list = document.getElementById('ft_list');
var button = document.getElementById('button');

function cookie()
{
	var i = 0;
	var cook = getCookie("id");
	while(cook[i])
	{
		var n = document.createElement("DIV");
		var t = document.createTextNode(cook[i]);
		n.setAttribute("id", cook[i]);
		n.addEventListener('click', function() {rmv(this);}, false);
		n.appendChild(t);
		list.insertBefore(n, list.firstChild);
		i++;
	}
}

function add()
{
	var todo = prompt("Add something to do", "");
	if (todo != null && todo !="")
	{
		var n = document.createElement("DIV");
		var t = document.createTextNode(todo);
		n.setAttribute("id", todo);
		n.addEventListener('click', function() {rmv(this);}, false);
		n.appendChild(t);
		list.insertBefore(n, list.firstChild);
		createCookie(todo);
		console.log(todo);
	}
}

function rmv(elem)
{
	if (confirm('Confirm ?'))
	{
		setCookie(elem.id, -1);
		console.log(elem);
		elem.parentElement.removeChild(elem);
		console.log(elem);
	}
}


function createCookie(cvalue)
{
	var d = new Date();
	d.setTime(d.getTime() + (1*24*60*60*1000));
	var expires = "expires="+d.toUTCString();
	document.cookie = cvalue + "=id; " + expires;
}

function getCookie(cname)
{
	var name = cname + "=";
	var ca = document.cookie.split(';');
	var tab = new Array;
	for(var i=0; i<ca.length; i++)
	{
		var c = ca[i];
		var next = c.split('=');
		tab[i] = next[0];
	}
	return tab;
}

function setCookie(cvalue, exdays)
{
	var d = new Date();
	d.setTime(d.getTime() + (exdays*24*60*60*1000));
	var expires = "expires="+d.toUTCString();
	document.cookie = cvalue + "=id; " + expires;
}
