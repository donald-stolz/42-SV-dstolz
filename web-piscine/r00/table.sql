--
-- Table structure for table `spacetbl`
--

CREATE TABLE `spacetbl` (
  `id` int(8) NOT NULL,
  `name` varchar(255) NOT NULL,
  `image` text NOT NULL,
  `price` int(15) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- data for table `spacetbl`
--
INSERT INTO `spacetbl` (`id`, `name`, `image`, `price`) VALUES
/*SPACE WEAPONS*/
(1, 'Space Nuke','images/trunp-missile.png', 750,000),
(2, 'Space Laser','images/laser.png', 2,000,000),
(3, 'Weapon Armory','images/armory.jpg', 666,000),
(4, 'Stealth Cloak', 'images/stealth-cloak.jpg', 3,000,000);
/*SPACE EXPLORATION CATEGORY*/
(5, 'Space Rover', 'images/rover.jpg', 1,500,000);
(6, 'Advanced AI', 'images/advanced-ai.png', 5,000,000);
(7, 'Space Probe', 'pr0b3', 'images/probe.jpg', 250,000);
(8, 'Space Vehicle', 'images/space-vehicle.jpg', 2,000,000);
/*CREW ITEMS CATEGORY*/
(9, 'Robo-Dog', 'images/robot-dog.jpg', 1,000,000);
(10, 'Newest Music of 2019', 'images/new-music.jpg', 100);
(11, 'Newest Movies of 2019', 'images/new-movies.jpg', 300);
(12, 'Newest Comics of 2019', 'images/new-comic.jpg', 250);
--
-- Indexes for table `spacetbl`
--

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `spacetbl`
--
ALTER TABLE `spacetbl`
  MODIFY `id` int(8) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=1;
COMMIT;
