proc compose {g h} {
	foreach a $h { lappend out [lindex $g $a-1] }
	set out
}

proc power {L pow} {
	set Lpow $L
	for {set i 1} {$i < $pow} {incr i} { 
		set Lpow [compose $Lpow $L] 
	}
	puts $Lpow
	return $Lpow
}

set x {2 3 4 5 1}
power $x 2

