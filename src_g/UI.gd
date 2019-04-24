extends CanvasLayer



# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.

func set_coordinates(x, y):
	$X.set_text("X = " + (x as String))
	$Y.set_text("X = " + (y as String))

# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass
