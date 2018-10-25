proc cycles {L} {
	dict set visited temp temp #create an arrangement for mapping values to keys. The dictname is visited
	set arr {}
	for {set i 0} {$i < [llength $L]} {incr i} {
		if {[dict exist $visited [expr $i+1] ] == 1} { #dict exist tests whether a visisted exists and is defined	
			continue
		} else {
			lappend arr ([expr $i+1]
			dict set visited [expr $i+1] true
			set j $i
			while { [dict exist $visited [lindex $L $j]] == 0 } {
				dict set visited [lindex $L $j] true
				lappend arr [lindex $L $j]
				set j [expr [lindex $L $j]-1]
			}
			lappend arr ) 
		}
	}
	puts $arr
	return $arr

}

cycles {3 4 1 5 2}
