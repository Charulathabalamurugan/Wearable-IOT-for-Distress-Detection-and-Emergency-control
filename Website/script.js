// Function to show a section and hide others
function showSection(sectionId) {
    // Hide all sections
    const sections = document.querySelectorAll('.content-section');
    sections.forEach(section => {
        section.classList.remove('active');
    });

    // Show the selected section
    const activeSection = document.getElementById(sectionId);
    activeSection.classList.add('active');
}

// By default, show the home section when the page loads
document.addEventListener('DOMContentLoaded', function() {
    showSection('home');
});
