proc invert {L} {
	set inv $L
	for {set i 0} {$i<[llength $L]} {incr i} {
		set pos [expr [lindex $L $i]-1]
		set inv [lreplace $inv $pos $pos [expr $i+1]]
	}
	puts $inv
	return $inv
}

invert {3 2 5 1 4}
