var fields = document.getElementsByClassName("board");
fields = Array.prototype.slice.call(fields, 0);

var iks = true;
var oks = false;

var win = [
	{"niz":[1,2,3], "counter_x":0, "counter_o":0},
	{"niz":[4,5,6], "counter_x":0, "counter_o":0},
	{"niz":[7,8,9], "counter_x":0, "counter_o":0},
	{"niz":[1,4,7], "counter_x":0, "counter_o":0},
	{"niz":[2,5,8], "counter_x":0, "counter_o":0},
	{"niz":[3,6,9], "counter_x":0, "counter_o":0},
	{"niz":[1,5,9], "counter_x":0, "counter_o":0},
	{"niz":[3,5,7], "counter_x":0, "counter_o":0}
];

var xPlayed = [];
var oPlayed = [];

var info = document.getElementById("victoryInfo");

fields.forEach(function(field) {
	field.addEventListener("click", function() {
		if(iks && this.dataset.value=="") {
			this.src = "images/x.png";
			this.dataset.value = "x";

			iks = false;
			oks = true;

			xPlayed.push(this.id);
		} else if (oks && this.dataset.value=="") {
			this.src = "images/o.png";
			this.dataset.value = "o";

			oks = false;
			iks = true;

			oPlayed.push(this.id);
		}

		win.forEach(function(object) {
			if(xPlayed.length > 2) {
				for(i=0; i<xPlayed.length; i++) {
					if(object.niz.toString().includes(xPlayed[i])) {
						object.counter_x++;
					}
				}

				if(object.counter_x == 3) {
					victoryInfo.innerHTML = "VICTORY X";
				} else {
					object.counter_x = 0;
				}
			}
			if(oPlayed.length > 2) {
				for(i=0; i<oPlayed.length; i++) {
					if(object.niz.toString().includes(oPlayed[i])) {
						object.counter_o++;
					}
				}

				if(object.counter_o	== 3) {
					victoryInfo.innerHTML = "VICTORY O";
				} else {
					object.counter_o = 0;
				}
			}
		});
	});
});