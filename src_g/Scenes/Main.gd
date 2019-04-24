extends Node


var pos_x
var pos_y

# Called when the node enters the scene tree for the first time.
func _ready():
	pos_x = 0
	pos_y = 0

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	var v = Vector2(0, 0)
	
	if Input.is_action_pressed("left"):
		v.x += 1
	if Input.is_action_pressed("up"):
		v.y += 1
	if Input.is_action_pressed("right"):
		v.x -= 1
	if Input.is_action_pressed("down"):
		v.y -= 1
	
	