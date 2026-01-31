// CLASS: BubbleSorter
// PURPOSE: A reusable container for sorting logic
CLASS BubbleSorter

    // FUNCTION: sort
    // INPUT: An array of numbers called 'data'
    // OUTPUT: The same array, sorted in ascending order
    METHOD sort(data)
        
        // Determine the length of the list once
        SET n TO length of data
        
        // OUTER LOOP: Controls how many times we pass through the list.
        // After each pass, the largest unsorted element "bubbles" to the end.
        FOR i FROM 0 TO n - 1
            
            // OPTIMIZATION: Track if a swap happened. 
            // If no swaps occur during a pass, the list is already sorted!
            SET swapped TO FALSE

            // INNER LOOP: Compares adjacent elements.
            // We subtract 'i' because the last 'i' elements are already in place.
            FOR j FROM 0 TO n - i - 2
                
                // Compare the current item with the next one
                IF data[j] > data[j + 1] THEN
                    
                    // SWAP: If they are in the wrong order, flip them
                    SET temp TO data[j]
                    SET data[j] TO data[j + 1]
                    SET data[j + 1] TO temp
                    
                    // Mark that we made a change this pass
                    SET swapped TO TRUE
                    
                END IF
            END FOR

            // If no two elements were swapped by the inner loop, break early
            IF swapped IS FALSE THEN
                BREAK OUTER LOOP
            END IF

        END FOR

        RETURN data
        
    END METHOD

END CLASS